set terminal svg size 400, 300 enhanced fname 'arial' fsize 10 butt solid
set output 'out.svg'
plot "hist.txt" using 1:2 smooth freq with boxes