echo "Test1 input: M (5, m(6, 8))"
./main < ./Tests/test1.txt

echo "Test2 input: M (m(4, 6), m(8, 0))"
./main < ./Tests/test2.txt

echo "Test3 input: m (4, 0)"
./main < ./Tests/test3.txt

echo "Test4 input: m ()"
./main < ./Tests/test4.txt

echo "Test5 input: M (2, 1, 9)"
./main < ./Tests/test5.txt

echo "Test6 input: m (2, M(0, 8)))))"
./main < ./Tests/test6.txt

echo "Test7 input: m (3, U(8, 7))"
./main < ./Tests/test7.txt