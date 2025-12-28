#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/fs.h> // location for character drivers used for file operations

// Read file operation - found in linux/fs.h line 2066
ssize_t char_file_read(struct file *char_test_inode, char __user *buffer, size_t, loff_t *char_offset){
       printk(KERN_NOTICE "My character_driver file is being read\n");
	return 0;
};
// Write to file - found in linux/fs.h line 2067
static ssize_t char_file_write(struct file *char_test_inode, const char __user *buffer, size_t count, loff_t *char_file){
       printk(KERN_NOTICE "Writing data with character driver \n");
	return 0;
}
// Open file operation - found in linux/fs.h line 2077
static int char_file_open(struct inode *char_test_inode, struct file *char_file){
	// run a message when this driver opens a file.
       printk(KERN_NOTICE "My character_driver file is open\n");
	return 0;
}
// Release/Close file operation - found in linux/fs.h line 2079
static int char_file_release(struct inode *char_test_inode, struct file *char_file){
       printk(KERN_NOTICE "My character_driver file has closed\n");
	   kfree(char_test_inode);
	return 0;
}
// this creates an object char_file_operations
static const struct file_operations char_file_operations = {     
	// defining functions within this object
	.owner = THIS_MODULE,
	.read = char_file_read,
	.write = char_file_write,
	.open = char_file_open,
	.release = char_file_release,
};

static int __init entry_function(void) {
	printk(KERN_NOTICE "Hello world from init module (character driver) \n");
	/* Register character driver using the prebuilt register_chrdev found in linux kernel.
	* To learn more about where its being used and how use it to go to 
	* https://elixir.bootlin.com/linux/v6.15.2/A/ident/register_chrdev
	*/
	register_chrdev(200, "test_char_driver", &char_file_operations);	
	return 0;
}

static void __exit exit_function(void) {
	printk("Good bye from exit module (character driver) \n");
	unregister_chrdev(200, "Test Character Driver");	
}

module_init(entry_function);
module_exit(exit_function);

MODULE_AUTHOR("tedleyem");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple character driver module");
