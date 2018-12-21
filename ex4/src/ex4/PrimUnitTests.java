package ex4;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.*;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429

 */
public class PrimUnitTests {
    Graph<String> graph;

    @Before
    public void setUp() {
        graph = new Graph<>(false);

        Vertex<String> a = new Vertex<String>("A");
        Vertex<String> b = new Vertex<String>("B");
        Vertex<String> c = new Vertex<String>("C");
        Vertex<String> d = new Vertex<String>("D");
        Vertex<String> e = new Vertex<String>("E");

        Edge<String> ab5 = new Edge<String>(a, b, 5);
        Edge<String> bc10 = new Edge<String>(b, c, 10);
        Edge<String> ac6 = new Edge<String>(a, c, 6);
        Edge<String> de6 = new Edge<String>(d, e, 6);

        graph.addEdge(ab5);
        graph.addEdge(bc10);
        graph.addEdge(ac6);
        graph.addEdge(de6);
    }

    @Test
    public void testPrim() {
        Prim<String> algorithm = new Prim<String>();
        Graph<String> forest =  algorithm.mst(graph, new Vertex<>("A"));
        assertEquals(17.0, forest.weight(),0);
    }

    // For automaticly run all the tests
    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(PrimUnitTests.class);
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
        System.out.println("\nPrimUnitTests result: " + result.wasSuccessful());
    }
}
