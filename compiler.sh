#! /bin/bash
rm -rf *.class *.o *.so
path="/usr/lib/jvm/"
if [ ! -d $path ]
then
	echo "Java n'est pas installe" >&2
	exit 1
fi
which gcc >/dev/null &>/dev/null
if [ $? -eq 1 ]
then
	echo "Gcc n'est pas installe" >&2
	exit 2
fi 

path=$path`ls /usr/lib/jvm/ | grep java-1.* | cut -f1 -d " " | tail -n1`
gcc -Wall -std=c99 -fPIC -c -I$path/include -I$path/include/linux *.c
gcc -Wall -std=c99 -fPIC -shared *.o -o libInterfaceWithC.so
export LD_LIBRARY_PATH="InterfaceWithC":$LD_LIBRARY_PATH
javac *.java
echo 'Use "export LD_LIBRARY_PATH="InterfaceWithC":$LD_LIBRARY_PATH" before launching the game'
echo '"./hex for playing'
chmod +x hex
exit 0

