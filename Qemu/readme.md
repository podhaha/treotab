
```sudo qemu-system-x86_64 -m 9G -cpu host -boot order=c -drive file=Nexus.LiteOS.11.x64.ISO,media=cdrom -drive file=win.img,format=raw -device usb-ehci,id=usb,bus=pci.0,addr=0x4 -device usb-tablet -vnc :0 -smp cores=3,threads=3,sockets=1 -device rtl8139,netdev=n0 -netdev user,id=n0 -vga vmware -accel kvm
```
```
sudo qemu-system-x86_64 -m 9G -cpu host -boot order=c -drive file=win.img,format=raw -device usb-ehci,id=usb,bus=pci.0,addr=0x4 -device usb-tablet -vnc :0 -smp cores=3,threads=3,sockets=1 -device rtl8139,netdev=n0 -netdev user,id=n0 -vga vmware -accel kvm
```
```
sudo qemu-system-x86_64 -m 9G -cpu qemu64 -boot order=c -drive file=win.img,format=raw -device usb-ehci,id=usb,bus=pci.0,addr=0x4 -device usb-tablet -vnc :0 -smp cores=3,threads=3,sockets=1 -device rtl8139,netdev=n0 -netdev user,id=n0 -vga vmware
```
