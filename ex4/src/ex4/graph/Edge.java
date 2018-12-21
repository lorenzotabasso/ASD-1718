package ex4.graph;

import java.util.Objects;

/**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 *
 * Edge class
 *
 * @param <T> Generic Type
 */
public class Edge<T>{
    private Vertex<T> vertex1, vertex2;
    private double weight;

    /**
     * Costructor of Edge Object.
     *
     * @param v1 the first vertex
     * @param v2 the second vertex
     * @param weight the weight of the edge
     */
    public Edge(Vertex<T> v1, Vertex<T> v2, double weight){
        vertex1 = v1;
        vertex2 = v2;
        this.weight = weight;
    }

    /**
     * Gets vertex1
     *
     * @return vertex1
     */
    public Vertex<T> getVertex1() {
        return vertex1;
    }

    /**
     * Gets vertex2
     *
     * @return vertex2
     */
    public Vertex<T> getVertex2() {
        return vertex2;
    }

    /**
     * Gets the weight of the edge
     *
     * @return weight
     */
    public double getWeight() {
        return weight;
    }

    /**
     * Overrides the behavior of the method equals to return true if equals,
     * false otherwise
     *
     * @return true if they are equal, false otherwise
     */
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (!(obj instanceof Edge))
            return false;

        Edge _obj = (Edge) obj;
        return _obj.vertex1.equals(vertex1) && _obj.vertex2.equals(vertex2)
                && _obj.weight == weight;
    }

    /**
     * Overrides the behavior of the method hashCode (it needs for the equals method)
     *
     * @return int hashcode
     */
    @Override
    public int hashCode() {
        int hash = 28;
        hash = 5 * hash + Objects.hashCode(vertex1);
        hash = 5 * hash + Objects.hashCode(vertex2);
        hash = 5 * hash + Objects.hashCode(this.weight);
        return hash;
    }
}