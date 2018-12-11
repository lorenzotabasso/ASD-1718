package ex4;

import java.util.Objects;

/**
 /**
 * @author Lorenzo Tabasso, mat: 812499
 * @author Andrea Malgaoli, mat: 823429
 * Vertex class
 * @param <T> Generic Type
 */
public class Vertex<T> {
    private T label;

    public Vertex(T label) {

        this.label = label;
    }

    /**
     * Gets label
     *
     * @return <T> Generic type label
     */
    public T getLabel() {
        return label;
    }

    /**
     * Overrides the behavior of the method to create a string starting from the
     * Vertex object
     *
     * @return Vertex object printed into String
     */
    @Override
    public String toString() {

        return label.toString();
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
        if (!(obj instanceof Vertex))
            return false;

        Vertex _obj = (Vertex) obj;
        return (_obj.label == null ? label == null : _obj.label.equals(label));
    }

    /**
     * Overrides the behavior of the method hashCode (it needs for the equals method)
     *
     * @return int hashcode
     */
    @Override
    public int hashCode() {
        int hash = 28;
        hash = 10 * hash + Objects.hashCode(label);
        return hash;
    }

}
