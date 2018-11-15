#include <string>

class DFT_Search
{
public:
    DFT_Search();
    DFT_Search(char* s_vertex, std::string in_graph);
    DFT_Search(char* s_vertex, char* d_vertex, std::string in_graph);
    void Start(void);
    virtual ~DFT_Search();

protected:

private:
    static const int adj_matrix_size = 6;
    void ParseMatrix(std::string file_name);
    int s_vertex_number; // starting vertex as number
    int d_vertex_number; // starting vertex as number
    int adj_matrix[adj_matrix_size][adj_matrix_size]; // adjacency matrix
    void Step(void);
};
