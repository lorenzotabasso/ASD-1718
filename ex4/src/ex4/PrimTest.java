package ex4;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
import static org.junit.Assert.*;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */
public class PrimTest {
    private Graph<String> graph;

    @Before
    public void Before() {
        graph = new Graph<>(false);
        String path = "/Volumes/HDD/Lorenzo/Downloads/laboratorio-algoritmi-2017-18/Datasets/ex4/italian_dist_graph.csv";
        FileUtils.GraphCSV(graph, path);
    }

    @Test
    public void TestDataSet() {
        Prim<String> algorithm = new Prim<String>();
        Graph<String> forest = algorithm.mst(graph, new Vertex<String>("francavilla fontana"));

        System.out.format("Nodi: %d", forest.getVertices().size()).println();
        System.out.format("Archi: %d",forest.getEdges().size()).println();
        System.out.format("Peso: %.3f Km", forest.weight()/1000).println();

        assertEquals(18640, forest.getVertices().size());
        assertEquals(18637, forest.getEdges().size());
        assertEquals(89939.913f,forest.weight()/1000, 0.02f);
    }

    // For automaticly run all the tests
    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(PrimTest.class);
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        System.out.println("\nPrimTest result: " + result.wasSuccessful());
    }
}