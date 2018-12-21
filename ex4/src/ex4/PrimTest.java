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
    private Graph<String> simpleGraph;
    private Graph<String> datasetGraph;

    @Before
    public void setUp() {
        simpleGraph = new Graph<>(false);

        Vertex<String> a = new Vertex<String>("A");
        Vertex<String> b = new Vertex<String>("B");
        Vertex<String> c = new Vertex<String>("C");
        Vertex<String> d = new Vertex<String>("D");
        Vertex<String> e = new Vertex<String>("E");

        Edge<String> ab5 = new Edge<String>(a, b, 5);
        Edge<String> bc10 = new Edge<String>(b, c, 10);
        Edge<String> ac6 = new Edge<String>(a, c, 6);
        Edge<String> de6 = new Edge<String>(d, e, 6);

        simpleGraph.addEdge(ab5);
        simpleGraph.addEdge(bc10);
        simpleGraph.addEdge(ac6);
        simpleGraph.addEdge(de6);

        datasetGraph = new Graph<>(false);
        String path = "/Volumes/HDD/Lorenzo/Downloads/laboratorio-algoritmi-2017-18/Datasets/ex4/italian_dist_graph.csv";
        FileUtils loader = new FileUtils();
        loader.GraphCSV(datasetGraph, path);
    }

    @Test
    public void testSimpleGraph() {
        Prim<String> algorithm = new Prim<String>();
        Graph<String> forest =  algorithm.mst(simpleGraph, new Vertex<>("A"));
        assertEquals(17.0, forest.getGraphWeight(),0);
    }

    @Test
    public void testDatasetGraph() {
        Prim<String> algorithm = new Prim<String>();
        Graph<String> forest = algorithm.mst(datasetGraph, new Vertex<String>("francavilla fontana"));

        System.out.format("Nodi: %d", forest.getVertices().size()).println();
        System.out.format("Archi: %d",forest.getEdges().size()).println();
        System.out.format("Peso: %.3f Km", forest.getGraphWeight()/1000).println();

        assertEquals(18640, forest.getVertices().size());
        assertEquals(18637, forest.getEdges().size());
        assertEquals(89939.913f,forest.getGraphWeight()/1000, 0.02f);
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