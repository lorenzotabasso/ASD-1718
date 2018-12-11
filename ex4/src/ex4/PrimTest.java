package ex4;

import org.junit.Before;
import org.junit.Test;
/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 */
public class PrimTest {
    Graph<String> graph;

    @Before
    public void Before() {
        graph = new Graph(false);
        String path = "C:\\Users\\Luciano\\Desktop\\Ex4\\src\\Ex4\\italian_dist_graph.csv";
        FileUtils.GraphCSV(graph, path);
    }

    @Test
    public void TestDataSet() {
        Graph<String> forest = new Prim().mst(graph, new Vertex("francavilla fontana"));
        System.out.format("Peso: %.3f", forest.weight()/1000).println();
        System.out.format("Nodi: %d", forest.getVertices().size()).println();
        System.out.format("Archi: %d",forest.getEdges().size()).println();
    }
}