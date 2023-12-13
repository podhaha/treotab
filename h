read -p "Y To Confirm|N to Cancel[Y/N]: " input

case $input in

    Y)
    echo Ok;;
    y)
    echo ok;;
    N)
    echo Cancel && exit 1;;
    n)
    echo Cancel && exit 1;;
esac
echo Update Package and INSTALL QEMU
echo 0/2
sudo apt update -y &>/dev/null
echo 1/2
sudo apt install qemu-system -y &>/dev/null
echo 2/2
echo 
echo INSTALL FILE NGROK..
wget -O ngrok.tgz "https://bin.equinox.io/c/bNyj1mQVY4c/ngrok-v3-stable-linux-amd64.tgz" 2>/dev/null
echo extract File ngrok
tar -xf ngrok.tgz
clear
echo choose your region Ngrok
read -p "REGION_NGROK: " inpu
echo paste your authtoken
read -p "AUTHTOKEN_NGROK: " inp
./ngrok authtoken $inp
echo [         ]0/10
sleep 3
echo [#########]10/10
nohup ./ngrok tcp 5900 --region $inpu &>/dev/null &
echo Download OS file [0/2]
wget -O bios64.bin "https://github.com/BlankOn/ovmf-blobs/raw/master/bios64.bin" 2>/dev/null
echo 1/2
wget -O win.iso "https://go.microsoft.com/fwlink/p/?LinkID=2195404&clcid=0x409&culture=en-us&country=US" 2>/dev/null
echo 2/2
qemu-img create -f raw win.img 128G
echo SUF Boot[CTRL+C TO CANCEL]
sudo qemu-system-x86_64 -m 9G -cpu host -boot order=c -drive file=win.iso,media=cdrom -drive file=win.img,format=raw -device usb-ehci,id=usb,bus=pci.0,addr=0x4 -device usb-tablet -vnc :0 -smp cores=4 -device rtl8139,netdev=n0 -netdev user,id=n0 -vga qxl -accel kvm -bios bios64.bin &>/dev/null
pkill qemu && pkill ngrok && clear
