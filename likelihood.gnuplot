set terminal svg size 400, 300 enhanced fname 'arial' fsize 10 butt solid
set output 'likelihood.svg'
plot [0:6][0:8e-195] "likelihood.txt" using 1:2 with line