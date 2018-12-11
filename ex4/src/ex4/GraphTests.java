package ex4;


import org.junit.*;
import java.util.Set;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */
public class GraphTests {
    private Graph<String> graph;

    @Before
    public void setUp() {
        graph = new Graph(false);
        graph.addEdge(new Edge(new Vertex("A"), new Vertex("B"), 5));
        graph.addEdge(new Edge(new Vertex("B"), new Vertex("C"), 10));
        graph.addEdge(new Edge(new Vertex("A"), new Vertex("C"), 6));
        graph.addEdge(new Edge(new Vertex("D"), new Vertex("E"), 6));
    }

    @Test
    public void testContains(){
        assertTrue(graph.contains(new Vertex("A")));
    }

    @Test
    public void testAddEdge() {
        graph.addEdge(new Edge(new Vertex("A"), new Vertex("D"), 1));
        assertEquals(1.0, graph.getWeight(new Vertex("A"), new Vertex("D")),0);
    }

    @Test
    public void testGetAdjVertices() {
        Vertex result = null;
        for (Vertex v :(Set<Vertex>)graph.getAdjVertices(new Vertex("E")))
            result = v;
        assertEquals(new Vertex("D").getLabel(), result.getLabel());
    }

    @Test
    public void testToString() {

        assertEquals("", new Graph(false).toString());
    }

    @Test
    public void testGetWeight() {
        assertEquals(5.0, graph.getWeight(new Vertex("A"), new Vertex("B")),0);
    }

    @Test
    public void testWeight() {
        assertEquals(27.0, graph.weight(),0);
    }
}
