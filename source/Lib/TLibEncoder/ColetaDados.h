/* 
 * File:   ColetaDados.h
 * Author: mateuswn
 *
 * Created on 24 de Agosto de 2015, 16:08
 */

#include <string>
#include <stdio.h>
#include <sstream>
#include "../TLibCommon/TComMv.h"

#define	COLETADADOS_H 1

class ColetaDados {
public:
    ColetaDados();
    static void incrementaBlocosCalculados();
    static int getBlocosCalculados();
    static void resetBlocosCalculados();
    static void setInter();
    static void setFalse();
    static bool isInter();
    static void salvaPartIndex(int x);
    static int getPartIndex();
    static FILE* getFile();
    static void iniciaArquivo(std::string sequence, Double qp);
    static int getStep(int bestX, int bestY);
    static int getPred(int bestX, int bestY);
    static int getRaster();
    static void setRaster(int x);
    static int getRefinement();
    static void setRefinement(int x);
    static void setRefinementLevel();
    static void setFirstLevel();
    static void resetRefinementLevel();
    static void resetFirstLevel();
    static int getRefinementLevel();
    static int getFirstLevel();
    static TComMv& getMv(int x); // 0 = pred; 1 = first; 2 = raster; 3 = refinement;
    static TComMv& getPredMv(int x); // 0 = Median; 1 = Zero; 2 = Integer;
    static void setTotalLevel(int x);
    static void resetTotalLevel();
    static int getTotalLevel();
    static void setMaxLevel(int x);
    static int getMaxLevel();
    static void setIteration();
    static void resetIteration();
    static int getIteration();
private:
    static int iBlocosCalculados;
    static int partIndex;
    static int step; // 0 = predictor; 1 = first search; 2 = raster; 3 = refinement;
    static int raster; //if raster occurs;
    static int refinement; // if refinement occurs;
    static int firstLevel;
    static int refinementLevel;
    static FILE* fp;
    static TComMv predictorMv;
    static TComMv firstMv;
    static TComMv rasterMv;
    static TComMv refinementMv;
    static TComMv medianMv;
    static TComMv integerMv;
    static int pred;
    static int maxLevel;
    static int iteration;
    static int totalLevel;
};

