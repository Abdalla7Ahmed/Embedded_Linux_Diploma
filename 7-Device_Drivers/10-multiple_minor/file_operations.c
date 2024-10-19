#include "file_operations.h"



#define BUFFER_SIZE    100
static unsigned char buffer[BUFFER_SIZE];
unsigned int buffer_pointer = 0;
int Driver_Open(struct inode *device_file, struct file *instance)
{
    printk("%s device_file open was called \n",__FUNCTION__);
    return 0;
}
int Driver_release(struct inode *device_file, struct file *instance)
{
    printk("%s device_file release was called \n",__FUNCTION__);
    return 0;
}
ssize_t Driver_Read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset)
{
    int to_copy, not_copied, delta;
    int minor = iminor(file->f_inode);
    printk(KERN_INFO "[%s] minor is %d \n", __FUNCTION__,minor);
    // Determine how much data we can actually read
    to_copy = min((size_t)(buffer_pointer - *offset), count);

    // Check if there is no data left to read
    if (to_copy <= 0) {
        printk(KERN_INFO "[%s] No data left to read\n", __FUNCTION__);
        return 0;
    }

    // Copy data to user space
    not_copied = copy_to_user(user_buffer, buffer + *offset, to_copy);

    // Calculate how much was successfully copied
    delta = to_copy - not_copied;

    // Update the offset to reflect the new position
    *offset += delta;

    printk(KERN_INFO "[%s] Read %d bytes from offset %lld\n", __FUNCTION__, delta, *offset);
    return delta;
}

ssize_t Driver_Write(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
    int to_copy, not_copied, delta;
    int minor = iminor(file->f_inode);
    printk(KERN_INFO "[%s] minor is %d \n", __FUNCTION__,minor);
    // Determine how much data we can actually write
    to_copy = min(count, (size_t)(BUFFER_SIZE - *offset));

    // Check if there is no space left to write
    if (to_copy <= 0) {
        printk(KERN_INFO "[%s] No space left to write\n", __FUNCTION__);
        return -ENOMEM;
    }

    // Copy data from user space
    not_copied = copy_from_user(buffer + *offset, user_buffer, to_copy);

    // Calculate how much was successfully copied
    delta = to_copy - not_copied;

    // Update the buffer pointer and offset
    buffer_pointer = max((unsigned int)buffer_pointer, (unsigned int)(*offset + delta));
    *offset += delta;

    printk(KERN_INFO "[%s] Written %d bytes at offset %lld\n", __FUNCTION__, delta, *offset);
    return delta;
}
