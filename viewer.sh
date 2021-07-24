make
git clone https://github.com/o-reo/push_swap_visualizer.git ../push_swap_visualizer
cp push_swap ../push_swap_visualizer/
cd ../push_swap_visualizer
python3 pyviz.py `ruby -e "puts (0..200).to_a.shuffle.join(' ')"`