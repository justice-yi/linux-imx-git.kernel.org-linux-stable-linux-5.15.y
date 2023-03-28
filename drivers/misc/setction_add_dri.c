#include <linux/kernel.h>
#include <linux/module.h>
#include <uapi/linux/sched.h>
#include <linux/init_task.h>
#include <linux/init.h>
#include <linux/fdtable.h>
#include <linux/fs_struct.h>
#include <linux/mm_types.h>
#include <linux/list.h>
#include <linux/types.h>



#define my_section __attribute__((__section__(".my_section")))

struct person{
	int age;
	char *name;
};


struct person my_section lzy ={
	18,
	"liangzhengyi",
};

extern const struct person my_section_begin[],my_section_end[];

static int __init section_add_init(void)
{
	
	struct person *addr_begin = my_section_begin;
	struct person *addr_end = my_section_end;
	
	printk("section_add_init\n");

	printk("find section %d %s",addr_begin->age,addr_begin->name);
	printk("my section lenth:%d\n",(my_section_end-my_section_begin)*sizeof(struct person));
	
 	return 0;
}


//内核模块退出函数
static void __exit section_add_exit(void)
{
 	printk("section_add_exit\n");
}

module_init(section_add_init);//入口
module_exit(section_add_exit);//出口
MODULE_LICENSE("GPL");//许可证


