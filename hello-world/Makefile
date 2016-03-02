KERNEL_VER = $(shell uname -r)

# kernel modules
obj-m += hello.o

# specify flags for the module compilation
EXTRA_CFLAGS = -g -O0

build: kernel_modules

kernel_modules:
	make -C /lib/modules/$(KERNEL_VER)/build M=$(CURDIR) modules

clean:
	make -C /lib/modules/$(KERNEL_VER)/build M=$(CURDIR) clean