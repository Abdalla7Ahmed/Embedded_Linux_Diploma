
obj-m += my_module.o

my_module-y := led_control.o file_operations.o

all:
	make -C /lib/modules/$(shell uname -r )/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r )/build M=$(PWD) clean