<p align="center"><img src="logo.png" width="180px" height="auto"></p>
<p align="center">A simple & lightweight x86 operating system</p>


### Building & Running
Use the `Makefile` in order to build the binaries/objects et cetera- with <a href="https://linux.die.net/man/1/make" target="_blank">make</a>.
<br>
**To build the OS image run**: `$ make os-image`
<br>
**To build the OS image (WITH GRUB) run**: `$ make grub`
<br><br>
#### Emulation
You can launch eOS with a VM like <a href="https://www.qemu.org/documentation/" target="_blank">qemu</a>. Launch *qemu* via *make* by running: `$ make run`.

	$ make (option)
		run : Runs the OS with qemu
		drun : Recompiles the OS and runs it with qemu
		clean : Remove all object/binary/image files

### Planned Features
Read `TODO.md` for planned features.

<br>
<br>
<br>
<br>

### Resources
These are the most common resources I used in order to build eOS. I highly recommend them.
##### Books
 - [Operating Systems: From 0 to 1](https://tuhdo.github.io/os01/) (Open-Source, unfinished)
 - [Writing a Simple Operating System - from Scratch](https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf)
##### Wikis
 - [OSDev.org](https://wiki.osdev.org/Expanded_Main_Page)
