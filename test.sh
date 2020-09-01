make
rm my_result.log
rm good_result.log

header()
{
	echo "-------------- $1 --------------" >> my_result.log 2>> my_result.log
	echo "-------------- $1 --------------" >> good_result.log 2>> good_result.log
}


# -----------------MD5---------------

header "md5 1"
echo "pickle rick" | ./ft_ssl md5 >> my_result.log 2>> my_result.log
echo "pickle rick" | md5 >> good_result.log 2>> good_result.log


header "md5 2"
echo "Do not pity the dead, Harry." | ./ft_ssl md5 -p >> my_result.log 2>> my_result.log
echo "Do not pity the dead, Harry." | md5 -p >> good_result.log 2>> good_result.log


header "md5 3"
echo "Pity the living." | ./ft_ssl md5 -q -r >> my_result.log 2>> my_result.log
echo "Pity the living." | md5 -q -r >> good_result.log 2>> good_result.log


header "md5 4"
echo "And above all," > file
./ft_ssl md5 file >> my_result.log 2>> my_result.log
md5 file >> good_result.log 2>> good_result.log


header "md5 5"
./ft_ssl md5 -r file >> my_result.log 2>> my_result.log
md5 -r file >> good_result.log 2>> good_result.log


header "md5 6"
./ft_ssl md5 -s "pity those that aren't following baerista on spotify." >> my_result.log 2>> my_result.log
md5 -s "pity those that aren't following baerista on spotify." >> good_result.log 2>> good_result.log


header "md5 7"
echo "be sure to handle edge cases carefully" | ./ft_ssl md5 -p file >> my_result.log 2>> my_result.log
echo "be sure to handle edge cases carefully" | md5 -p file >> good_result.log 2>> good_result.log


header "md5 8"
echo "some of this will not make sense at first" | ./ft_ssl md5 file >> my_result.log 2>> my_result.log
echo "some of this will not make sense at first" | md5 file >> good_result.log 2>> good_result.log


header "md5 9"
echo "but eventually you will understand" | ./ft_ssl md5 -p -r file >> my_result.log 2>> my_result.log
echo "but eventually you will understand" | md5 -p -r file >> good_result.log 2>> good_result.log


header "md5 10"
echo "GL HF let's go" | ./ft_ssl md5 -p -s "foo" file >> my_result.log 2>> my_result.log
echo "GL HF let's go" | md5 -p -s "foo" file >> good_result.log 2>> good_result.log


header "md5 11"
echo "one more thing" | ./ft_ssl md5 -r -p -s "foo" file -s "bar" >> my_result.log 2>> my_result.log
echo "one more thing" | md5 -r -p -s "foo" file -s "bar" >> good_result.log 2>> good_result.log


header "md5 12"
echo "just to be extra clear" | ./ft_ssl md5 -r -q -p -s "foo" file >> my_result.log 2>> my_result.log
echo "just to be extra clear" | md5 -r -q -p -s "foo" file >> good_result.log 2>> good_result.log


# -----------------SHA 256---------------

header "sha256 1"
echo "https://www.youtube.com/watch?v=w-5yAtMtrSM" > big_smoke_order_remix
./ft_ssl sha256 -q big_smoke_order_remix >> my_result.log 2>> my_result.log
echo "a8dc621c3dcf18a8a2eddae1845e8e5f6498970a867056ac5f7121ac3d66cfd9" >> good_result.log # openssl sha256 big_smoke_order_remix 2>> openssl sha256 big_smoke_order_remix


header "sha256 2"
echo "wubba lubba dub dub" | ./ft_ssl sha256 -q >> my_result.log 2>> my_result.log
echo "wubba lubba dub dub" | openssl sha256 >> good_result.log 2>> good_result.log


# -----------------SHA 224---------------

header "sha224 1"
echo "https://www.youtube.com/watch?v=w-5yAtMtrSM" > big_smoke_order_remix
./ft_ssl sha224 -q big_smoke_order_remix >> my_result.log 2>> my_result.log
echo "abe47d133991621601248ca56b52cbef51090270d540f5fa8486a605" >> good_result.log # openssl sha224 big_smoke_order_remix 2>> openssl sha224 big_smoke_order_remix


header "sha224 2"
echo "wubba lubba dub dub" | ./ft_ssl sha224 -q >> my_result.log 2>> my_result.log
echo "wubba lubba dub dub" | openssl sha224 >> good_result.log 2>> good_result.log

diff my_result.log good_result.log
rm big_smoke_order_remix
