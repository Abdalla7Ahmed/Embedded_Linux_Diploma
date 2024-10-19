#ifndef FILE_OPERATIONS
#define FILE_OPERATIONS

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/minmax.h>
int Driver_Open(struct inode *device_file, struct file *instance);
int Driver_release(struct inode *device_file, struct file *instance);
ssize_t Driver_Read(struct file *file, char __user *user_buffer, size_t count, loff_t *offset);
ssize_t Driver_Write (struct file *file,const char __user *user_buffer, size_t count, loff_t *offset);

#endif // !FILE_OPERATIONS
