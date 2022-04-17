
##
### About
This is a simple & lightweight x86 operating-system that I created for fun. 

### Building & Running
Use the `Makefile` in order to build the binaries/objects et cetera- with <a href="https://linux.die.net/man/1/make" target="_blank">make</a>.
<br>
**To build the OS image run**: `$ make eos.iso`
#### Emulation
You can launch eOS with <a href="https://www.qemu.org/documentation/" target="_blank">qemu</a>. Launch *qemu* via *make* by running: `$ make run`.

	$ make (option)
		run : Runs the OS with qemu
		drun : Recompiles the OS and runs it with qemu
		clean : Remove all object/binary/image files
