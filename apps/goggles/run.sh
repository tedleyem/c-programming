#/bin/bash
if [ ! -f goggles ]; then
    rm goggles
else
    echo "goggles not found"
fi

echo "cc main.c -o goggles"
cc main.c -o goggles 

echo "Running goggles app"
./goggles
