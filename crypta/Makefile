#a standard Makefile, except we add test part after we run "make".
#a test part is used for testing modules, for example "make test"

obj-m += crypta.o
all:
        $(MAKE) -C /lib/modules/$(shell uname -r)/build CC=$(CC) M=$(PWD) modules

clean:
        $(MAKE) -C /lib/modules/$(shell uname -r)/build CC=$(CC) M=$(PWD) clean
        $(RM) other/cat_noblock *.plist
test:
        sudo rmmod crypta
        sudo dmesg -C
        sudo insmod crypta.ko
        dmesg
