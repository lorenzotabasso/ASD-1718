package ex4;

import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
import static org.junit.Assert.*;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429

 */
public class PrimUnitTests {
    Graph<String> graph;

    @Before
    public void setUp() {
        graph = new Graph(false);
        graph.addEdge(new Edge(new Vertex("A"), new Vertex("B"), 5));
        graph.addEdge(new Edge(new Vertex("B"), new Vertex("C"), 10));
        graph.addEdge(new Edge(new Vertex("A"), new Vertex("C"), 6));
        graph.addEdge(new Edge(new Vertex("D"), new Vertex("E"), 6));
    }

    @Test
    public void testPrim() {
        Graph forest =  new Prim().mst(graph, new Vertex("A"));
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
