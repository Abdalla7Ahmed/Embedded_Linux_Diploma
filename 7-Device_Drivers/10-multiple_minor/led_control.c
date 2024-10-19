#include "file_operations.h"

/* Meta information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abdallah Ahmed Mohammed ");
MODULE_DESCRIPTION("test parameters");

#define MODULE_NAME "my_module"
#define MINOR_BASE 0
#define N_MINOR_DEVICES 5


#define CLASS_NAME "my_class"
#define DEVICE_NAME "my_device"

struct MyData{
    struct device *device_file[N_MINOR_DEVICES];
    dev_t device_number;
    struct class *device_class;
    struct cdev st_character_device;
    const struct file_operations fops;
}MyData_st = {
    .fops={
        .owner = THIS_MODULE,
        .open = Driver_Open,
        .release = Driver_release,
        .read = Driver_Read,
        .write = Driver_Write
    }
};


static int __init Module_init(void)
{
    int retval;
    int i;
    printk("hello Kernel this is the init module function \n");
    retval = alloc_chrdev_region(&MyData_st.device_number,MINOR_BASE,N_MINOR_DEVICES,MODULE_NAME);
    if (retval==0 )
    {
        printk("%s retval = %d , registered device major number = %d and minor number = %d \n",__FUNCTION__,retval,MAJOR(MyData_st.device_number),MINOR(MyData_st.device_number));
    }else
    {
        printk("cann't register device major number \n");
        return -1;
    }
    cdev_init(&MyData_st.st_character_device,&MyData_st.fops);
    retval = cdev_add(&MyData_st.st_character_device,MyData_st.device_number,N_MINOR_DEVICES);
    if (retval != 0)
    {
        printk("Registration of the devie failed \n");
       goto ERROR_ALLOCATE;
    }
    MyData_st.device_class = class_create(CLASS_NAME);
    if(MyData_st.device_class == NULL)
    {
       printk("Creating device class failed\n");
       goto ERROR_CLASS_CREATE;
    }

     // Create device files for each minor device
    for (i = 0; i < N_MINOR_DEVICES; i++) {
        MyData_st.device_file[i] = device_create(MyData_st.device_class, NULL, MKDEV(MAJOR(MyData_st.device_number), MINOR_BASE + i), NULL, "%s%d", DEVICE_NAME, MINOR_BASE + i);
        if (IS_ERR(MyData_st.device_file[i])) {
            printk("Creating device file for minor %d failed\n", MINOR_BASE + i);
            retval = PTR_ERR(MyData_st.device_file[i]);
            goto ERROR_DEVICE_FILE_CREATE;
        }
    } 
    return 0;




    ERROR_DEVICE_FILE_CREATE:
        while (--i >= 0) {
        device_destroy(MyData_st.device_class, MKDEV(MAJOR(MyData_st.device_number), MINOR_BASE + i));
        }
    ERROR_CLASS_CREATE:
        cdev_del(&MyData_st.st_character_device);
    ERROR_ALLOCATE:
        unregister_chrdev_region(MyData_st.device_number,N_MINOR_DEVICES);
        return -1;

      
}

static void __exit Module_exit(void)
{
    int i;
    for (i = 0; i < N_MINOR_DEVICES; i++) {
        device_destroy(MyData_st.device_class, MKDEV(MAJOR(MyData_st.device_number), MINOR_BASE + i));
    }
    class_destroy(MyData_st.device_class);
    cdev_del(&MyData_st.st_character_device);
    unregister_chrdev_region(MyData_st.device_number,1);
    printk("Goodbye Kernel this is the exit module function \n");
}

module_init(Module_init);
module_exit(Module_exit);









