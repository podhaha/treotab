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
sudo apt update -y
if command -v qemu-system-x86_64 &> /dev/null
command -v qemu-img &> /dev/null
then sudo apt install qemu-system -y
fi

