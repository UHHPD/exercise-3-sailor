set terminal svg size 400, 300 enhanced fname 'arial' fsize 10 butt solid
set output 'likelihood2.svg'
plot [0:6][880:1500] "nll.txt" using 1:2 with line