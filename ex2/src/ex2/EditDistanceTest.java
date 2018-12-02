package ex2;

import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
import static org.junit.Assert.*;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */

public class EditDistanceTest {

    /*
    FOR COMPILING AND RUNNING 
    (for better information see README.md in "laboratorio-algoritmi-2017-18/ex2")
    
    1. Go with ter terminal inside "laboratorio-algoritmi-2017-18/ex2/src"
    2. For compile Unit Tests launch the next commmand:
        "javac -cp .:../../Resources/java/JUnit/junit-4.12.jar:../../Resources/java/JUnit/hamcrest-core-1.3.jar ex2/EditDistanceTest.java"
    3. For execute the Unit Tests launch the next commmand:
        "java -cp .:../../Resources/java/JUnit/junit-4.12.jar:../../Resources/java/JUnit/hamcrest-core-1.3.jar ex2/EditDistanceTest"
     */

    @Test
    public void editDistance() {
        assertEquals(0, EditDistance.editDistance("", ""));
        assertEquals(4, EditDistance.editDistance("casa", ""));
        assertEquals(5, EditDistance.editDistance("", "cassa"));
        assertEquals(1, EditDistance.editDistance("casa", "cassa"));
        assertEquals(2, EditDistance.editDistance("casa", "cara"));
        assertEquals(4, EditDistance.editDistance("tassa", "passato"));
        assertEquals(0, EditDistance.editDistance("pioppo", "pioppo"));
    }

    @Test
    public void editDistanceDynBottomUp() {
        assertEquals(0, EditDistance.editDistanceDynBottomUp("", ""));
        assertEquals(4, EditDistance.editDistanceDynBottomUp("casa", ""));
        assertEquals(5, EditDistance.editDistanceDynBottomUp("", "cassa"));
        assertEquals(1, EditDistance.editDistanceDynBottomUp("casa", "cassa"));
        assertEquals(2, EditDistance.editDistanceDynBottomUp("casa", "cara"));
        assertEquals(4, EditDistance.editDistanceDynBottomUp("tassa", "passato"));
        assertEquals(0, EditDistance.editDistanceDynBottomUp("pioppo", "pioppo"));
    }

    @Test
    public void editDistanceDynTopDown() {
        assertEquals(0, EditDistance.editDistanceDynTopDown("", ""));
        assertEquals(4, EditDistance.editDistanceDynTopDown("casa", ""));
        assertEquals(5, EditDistance.editDistanceDynTopDown("", "cassa"));
        assertEquals(1, EditDistance.editDistanceDynTopDown("casa", "cassa"));
        assertEquals(2, EditDistance.editDistanceDynTopDown("casa", "cara"));
        assertEquals(4, EditDistance.editDistanceDynTopDown("tassa", "passato"));
        assertEquals(0, EditDistance.editDistanceDynTopDown("pioppo", "pioppo"));
    }

    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(EditDistanceTest.class);
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        System.out.println("\nResult: " + result.wasSuccessful());
    }

}