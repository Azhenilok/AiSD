echo "Test 1: ((5 3) (1 2))"
./program < Tests/test01.txt

echo "Test 2: ((5 3) (1 2))"
./program < Tests/test02.txt

echo "Test 3: ((5 ((142 67) (6 7))) (1 2))"
./program < Tests/test03.txt

echo "Test 4: ((13 ((11 2) (2 ((1 1) (7 3))))) (19 ((3 2) (17 19))))"
./program < Tests/test04.txt

echo "Test 5: ((5 2) (5 ((2 19) (14 6))))"
./program < Tests/test05.txt

echo "Test 6: ((13 ((11 2) (2 ((1 1) (7 3))))) (19 ((3 2) (17 ((2 2) (4 6))))))"
./program < Tests/test06.txt

echo "Test 7: ((1 1)(1))"
./program < Tests/test07.txt

echo "Test 8: ((11adsa 5) (4 3))"
./program < Tests/test08.txt

echo "Test 9: ds((1 6) (4 3))"
./program < Tests/test09.txt

echo "Test 10: ((1 6) (4 3))))))))))"
./program < Tests/test10.txt

echo "Test 11: ((1 6) (4 3)dasda)"
./program < Tests/test11.txt

echo "Test 12: ((dsa1 6) (4 3))"
./program < Tests/test12.txt
