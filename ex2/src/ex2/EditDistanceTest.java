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