int i;

    if(column == n){
        return 1;
    }

    for(i=0; i<n; i++){
        if(isSafe(chessBoard, i, column)){
            chessBoard[i][column] = 1;

            if(positionQueens(chessBoard, column+1)){
                return 1;
            }
        }

        chessBoard[i][column] = 0;
    }

    return 0;
