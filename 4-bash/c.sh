#!/bin/bash

echo "#!/bin/bash" >$1
echo "################### $1 #####################" >>$1
echo >>$1
chmod u+x $1
code $1
