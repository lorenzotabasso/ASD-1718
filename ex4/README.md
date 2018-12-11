# NOTE:
1. The test of the dataset is made in the *PrimTest.java* class.
2. To correctly run all the test is **necessary** to put inside 
*laboratorio-algoritmi-2017-18/ex4/src/ex4* folder all the ex3 classes
(PQueue, PQueueTests and PQueueItem) which can be found in the 
*laboratorio-algoritmi-2017-18/ex3/src/ex3/* folder.

# Instruction for compile and execute this program:

## Compiling and running Unit Tests:
1. Copy PQueue, PQueueTests and PQueueItem files from *laboratorio-algoritmi-2017-18/ex3/src/ex3/* 
(Remember to **change the package from ex3 to ex4**)
folder to *laboratorio-algoritmi-2017-18/ex4/src/ex4*
2. Go with ter terminal inside *laboratorio-algoritmi-2017-18/ex4/src*
3. For compile Unit Tests launch the next commmand:
*javac -cp .:../../Resources/java/JUnit/junit-4.12.jar:../../Resources/java/JUnit/hamcrest-core-1.3.jar ex4/GraphTests.java ex4/PrimTest.java ex4/PrimUnitTests.java*
4. For execute the Unit Tests launch the following commmands (one command at time):
- *java -cp .:../../Resources/java/JUnit/junit-4.12.jar:../../Resources/java/JUnit/hamcrest-core-1.3.jar ex4/GraphTests*
- *java -cp .:../../Resources/java/JUnit/junit-4.12.jar:../../Resources/java/JUnit/hamcrest-core-1.3.jar ex4/PrimTest*
- *java -cp .:../../Resources/java/JUnit/junit-4.12.jar:../../Resources/java/JUnit/hamcrest-core-1.3.jar ex4/PrimUnitTests*