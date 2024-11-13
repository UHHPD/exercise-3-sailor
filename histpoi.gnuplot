set terminal svg size 400, 300 enhanced fname 'arial' fsize 10 butt solid
set output 'outpoi.svg'
plot "./histpoi.txt" using 1:2, "./histpoi.txt" using 1:3 smooth freq with boxes