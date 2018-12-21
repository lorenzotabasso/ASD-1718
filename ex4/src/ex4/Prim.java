package ex4;

import java.util.HashMap;

/***
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 *
 * Class for Prim's algorithm implementation
 */
public class Prim<T> {

    /**
     * Prim's algorithm implementation
     *
     * @param graph weighted and undirected
     * @param start starting Vertex
     * @return Graph oriented: minimum spanning tree of the graph
     */
    public Graph<T> mst(Graph<T> graph, Vertex<T> start) {
        if (!graph.contains(start) || graph.isOriented())
            return null;

        HashMap<Vertex<T>, Vertex<T>> parent = new HashMap<>();
        HashMap<Vertex<T>, Double> distance = new HashMap<>();
        PQueue<Vertex<T>, Double> queue = new PQueue<>();
        Graph<T> forest = new Graph<>(true);

        for (Vertex<T> v : graph.getVertices())
            distance.put(v, Double.MAX_VALUE);

        parent.put(start, null);
        distance.put(start, 0.0);

        for (Vertex<T> v : graph.getVertices())
            queue.insert(v, distance.get(v));

        double weight;
        while (!queue.isEmpty()) {
            Vertex<T> u = queue.pullFirst();
            for (Vertex<T> v : graph.getAdjVertices(u)) {
                weight = graph.getEdgeWeight(u, v);
                if (!queue.isEmpty() && weight < distance.get(v)) {
                    parent.put(v, u);
                    distance.put(v, weight);
                    queue.setPriority(v, weight);
                }
            }

            Vertex<T> father = parent.get(u);
            forest.addVertex(u);
            if (father != null)
                forest.addEdge(new Edge<>(father, u, graph.getEdgeWeight(father, u)));
        }
        return forest;
    }
}
