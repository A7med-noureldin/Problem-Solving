class Spreadsheet {
private:
    vector<vector<int>> matrix;

    int rowNumber(const string &cell) {
        int row = 0;
        for (int i = 1; i < (int)cell.size(); i++) {
            row = row * 10 + (cell[i] - '0');
        }
        return row - 1; 
    }

    int getCellValue(const string &cell) {
        if (isdigit(cell[0])) {
            return stoi(cell); 
        }
        int row = rowNumber(cell);
        int col = cell[0]-'A';
        return matrix[row][col];
    }
public:
    Spreadsheet(int rows):matrix(rows, vector<int>(26, 0)){};

    void setCell(string cell, int value) {
        int row = rowNumber(cell);
        matrix[row][cell[0]-'A'] = value;
    }
    
    void resetCell(string cell) {
        int row = rowNumber(cell);
        matrix[row][cell[0]-'A'] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        int pos = formula.find('+');
        string cell1 = formula.substr(0, pos);
        string cell2 = formula.substr(pos + 1);
        return getCellValue(cell1) + getCellValue(cell2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */