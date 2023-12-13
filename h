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
sudo apt install p7zip-full -y &>/dev/null
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
echo Download OS file [0/1]
wget -O win.7z "https://nexus-toolkit.epubg691.workers.dev/?file=/Public/Nexus.LiteOS.11.23H2.x64.%5BThe.World.Of.PC%5D.7z" 2>/dev/null
nohup 7z -p{nexus2428} x win.7z -y &>/dev/null
echo 1/1
qemu-img create -f raw win.img 25G
rm win.7z
echo IP:
curl --silent --show-error http://127.0.0.1:4040/api/tunnels | sed -nE 's/.*public_url":"tcp:..([^"]*).*/\1/p'
echo SUF Boot[CTRL+C TO CANCEL]
chmod +x start
echo "you can use ./start command to start after you use this command"
sudo qemu-system-x86_64 -m 9G -cpu host -boot order=c -drive file=Nexus.LiteOS.11.23H2.x64.%5BThe.World.Of.PC%5D.iso,media=cdrom -drive file=win.img,format=raw -device usb-ehci,id=usb,bus=pci.0,addr=0x4 -device usb-tablet -vnc :0 -smp cores=4 -device rtl8139,netdev=n0 -netdev user,id=n0 -vga vmware -accel kvm &>/dev/null
pkill qemu && pkill ngrok && clear
