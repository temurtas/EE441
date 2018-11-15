fstream file_input(file_name.c_str(), fstream::in); // read input file

    // parse input text to aj_matrix
    while (file_input >> skipws >> matrix_entry) {
        for(uint8_t j=0; j<adj_matrix_size; j++)
            adj_matrix[i][j] = matrix_entry[j]-48; // character to integer
        i++;
    }




    ifstream inputFile;
    inputFile.open("EE441HW1.txt");
    int myarray[6][6];
    char array;


    fstream file_input("EE441HW1.txt", fstream::in); // read input file

    int count=0;

    while(!inputFile.eof())
    {
        inputFile.get(array) ;
        int i=0;
        while (i<6){

                int j=0;
                while (j<6){
                        myarray[i][j]=array;
                        j++;}
                i++;}

        cout<<array;
        count++;
    }



    cout<<"\n"<<myarray[0][0];
