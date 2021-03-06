#include <boost/graph/adjacency_list.hpp>
#include <string>
//describing the graph type
typedef std::string vertex_t;

typedef boost::adjacency_list<
    boost::vecS
    , boost::vecS
    , boost::bidirectionalS
    , vertex_t
> graph_type;

#include <boost/utility/string_ref.hpp>
#include <iostream>
// make a function that searches for some vertex
template <class GraphT>
void find_and_print(const GraphT& g, boost::string_ref name) {
    typedef typename boost::graph_traits<graph_type>
            ::vertex_iterator vert_it_t;
    vert_it_t it, end;
    boost::tie(it, end) = boost::vertices(g);

    // run a search for the required vertex
    typedef boost::graph_traits<graph_type>::vertex_descriptor desc_t;
    for (; it != end; ++ it) {
        desc_t desc = *it;
        if (boost::get(boost::vertex_bundle, g)[desc] == name.data()) {
            break;
        }
    }

    assert(it != end);
    std::cout << name << '\n';
} /* find_and_print */

int main() {
    //we construct it
    graph_type graph;

    //Let's carry out some undocumented trick that speeds up graph construction
    static const std::size_t vertex_count = 5;
    graph.m_vertices.reserve(vertex_count);
    /*
    C++ -> STL -> Boost -> C++ guru <- C
    */

    //add vertexes to the graph
    typedef boost::graph_traits<graph_type>
            ::vertex_descriptor descriptor_t;
    descriptor_t cpp
        = boost::add_vertex(vertex_t("C++"), graph);
    descriptor_t stl
        = boost::add_vertex(vertex_t("STL"), graph);
    descriptor_t boost
        = boost::add_vertex(vertex_t("Boost"), graph);
    descriptor_t guru
        = boost::add_vertex(vertex_t("C++ guru"), graph);
    descriptor_t ansic
        = boost::add_vertex(vertex_t("C"), graph);

    BOOST_STATIC_ASSERT((boost::is_same<descriptor_t, std::size_t>::value));

    //It is time to connect vertexes with edges
    boost::add_edge(cpp, stl, graph);
    boost::add_edge(stl, boost, graph);
    boost::add_edge(boost, guru, graph);
    boost::add_edge(ansic, guru, graph);


    find_and_print(graph, "Boost");
    find_and_print(graph, "C++ guru");
}
