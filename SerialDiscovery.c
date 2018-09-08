// simple serial device command line discovery with JSON output

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <libudev.h> // sudo apt-get install libudev-dev

void die(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

void add(struct udev_device *dev)
{
	struct udev_device *pdev;
	const char *vid, *pid, *ser, *name;
	const char *devnode;

	pdev = udev_device_get_parent_with_subsystem_devtype(dev, "usb", "usb_device");
	if (!pdev) return;
	devnode = udev_device_get_devnode(dev);
	if (!devnode) return;
	vid = udev_device_get_sysattr_value(pdev, "idVendor");
	pid = udev_device_get_sysattr_value(pdev, "idProduct");
	ser = udev_device_get_sysattr_value(pdev, "serial");
	name = udev_device_get_sysattr_value(pdev, "product");
	printf("{\n  \"address\": \"%s\",\n  \"online\": true,\n", devnode);
	if (name) {
		printf("  \"label\": \"%s (%s)\",\n", devnode, name);
		printf("  \"boardName\": \"%s\",\n", name);
	} else {
		printf("  \"label\": \"%s\",\n", devnode);
	}
	if (vid) {
		 printf("  \"vid\": \"%s\",\n", vid);
	}
	if (pid) {
		 printf("  \"pid\": \"%s\",\n", pid);
	}
	if (ser) {
		 printf("  \"iserial\": \"%s\",\n", ser);
	}
	printf("  \"protocol\": \"Serial Device\"\n}\n"); // probably not correct
}

void del(struct udev_device *dev)
{
	const char *devnode;

	devnode = udev_device_get_devnode(dev);
	if (!devnode) return;
	printf("{\n  \"address\": \"%s\",\n  \"online\": false\n}\n", devnode); 
}

int main()
{
	struct udev *udev=NULL;
	struct udev_monitor *mon=NULL;
	struct udev_enumerate *enumerate;
	struct udev_list_entry *devices, *entry;
	struct udev_device *dev;
	const char *path, *action;

	//printf("begin SerialDiscovery\n");

	udev = udev_new();
	if (!udev) die("unable to use udev");
	mon = udev_monitor_new_from_netlink(udev, "udev");
	udev_monitor_filter_add_match_subsystem_devtype(mon, "tty", NULL);
	udev_monitor_enable_receiving(mon);

	enumerate = udev_enumerate_new(udev);
	udev_enumerate_add_match_subsystem(enumerate, "tty");
	udev_enumerate_scan_devices(enumerate);
	devices = udev_enumerate_get_list_entry(enumerate);
	udev_list_entry_foreach(entry, devices) {
		path = udev_list_entry_get_name(entry);
		dev = udev_device_new_from_syspath(udev, path);
		if (dev) add(dev);
	}
	udev_enumerate_unref(enumerate);

	while (1) {
		dev = udev_monitor_receive_device(mon);
		if (!dev) continue;
		action = udev_device_get_action(dev);
		if (!action) continue;
		if (strcmp(action, "add") == 0) {
			add(dev);
		} else if (strcmp(action, "remove") == 0) {
			del(dev);
		}
		udev_device_unref(dev);
	}
	return 0;
}

void die(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(stderr, format, args);
	va_end(args);
	exit(1);
}

