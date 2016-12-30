/* 
 * File:   ColetaDados.cpp
 * Author: mateuswn
 * 
 * Created on 24 de Agosto de 2015, 16:08
 */

#include "ColetaDados.h"

int ColetaDados::iBlocosCalculados;
int ColetaDados::partIndex;
int ColetaDados::step; // 0 = predictor; 1 = first search; 2 = raster; 3 = refinement;
int ColetaDados::raster;
int ColetaDados::refinement;
FILE *ColetaDados::fp;
int ColetaDados::firstLevel;
int ColetaDados::refinementLevel;
TComMv ColetaDados::predictorMv;
TComMv ColetaDados::firstMv;
TComMv ColetaDados::rasterMv;
TComMv ColetaDados::refinementMv;
TComMv ColetaDados::medianMv;
TComMv ColetaDados::integerMv;
int ColetaDados::pred;
int ColetaDados::maxLevel;
int ColetaDados::iteration;
int ColetaDados::totalLevel;

int ColetaDados::tamWidth;
int ColetaDados::tamHeight;
int ColetaDados::QP;
int ColetaDados::numPred;
int ColetaDados::numFirst;
int ColetaDados::numRaster;
int ColetaDados::numRefixFirst;
int ColetaDados::numRefixRaster;
unsigned int ColetaDados::predictorSAD;
unsigned int ColetaDados::firstSAD;
unsigned int ColetaDados::rasterSAD;
int ColetaDados::bestDistance;
unsigned int ColetaDados::RdCostPred;
unsigned int ColetaDados::RdCostFirst;
unsigned int ColetaDados::RdCostRaster;

ColetaDados::ColetaDados() {
    refinement=0;
    raster=0;
    step=0;
    partIndex=0;
    iBlocosCalculados=0;
    fp=NULL;
    firstLevel=0;
    refinementLevel=0;
    predictorMv.setZero();
    firstMv.setZero();
    rasterMv.setZero();
    refinementMv.setZero();
    medianMv.setZero();
    integerMv.setZero();
    pred=0;
    maxLevel=0;
    iteration=0;
    totalLevel=0;
    tamWidth=0;
    tamHeight=0;
    QP=0;
    numPred=0;
    numFirst=0;
    numRaster=0;
    numRefixFirst=0;
    numRefixRaster=0;
    predictorSAD=0;
    firstSAD=0;
    rasterSAD=0;
    bestDistance=0;
    RdCostPred=0;
    RdCostFirst=0;
    RdCostRaster=0;
}
int ColetaDados::getBlocosCalculados(){
    return iBlocosCalculados;
}
void ColetaDados::incrementaBlocosCalculados(){
    iBlocosCalculados++;
}
void ColetaDados::resetBlocosCalculados(){
    iBlocosCalculados=0;
}
FILE* ColetaDados::getFile(){
    return fp;
}
void ColetaDados::iniciaArquivo(std::string sequence, Double qp){
    std::string file;
    std::string filename;
    std::ostringstream strs;
    strs << qp;
    std::string str = strs.str();
    file=sequence;
    int pos=file.find_last_of("/");
    filename=file.substr(pos+1,(file.length()-4)-(pos+1))+"_"+str+".out";
    fp=fopen(filename.c_str(),"w");
}
int ColetaDados::getPartIndex(){
    return partIndex;
}
void ColetaDados::salvaPartIndex(int x){
    partIndex=x;
}
int ColetaDados::getStep(int bestX, int bestY){
    TComMv bestMv;
    bestMv.set(bestX, bestY);
    if(refinementMv==bestMv)
        step=3;
    if(rasterMv==bestMv)
        step=2;
    if(firstMv==bestMv)
        step=1;
    if(predictorMv==bestMv)
        step=0;
    
    return step;
}
int ColetaDados::getPred(int bestX, int bestY){
    TComMv bestMv;
    bestMv.set(bestX, bestY);
    if(integerMv==bestMv)
        pred=2;
    if(TComMv(0,0)==bestMv)
        pred=1;
    if(medianMv==bestMv)
        pred=0;
    
    return pred;
}
int ColetaDados::getRaster(){
    return raster;
}
void ColetaDados::setRaster(int x){
    raster=x;
}
int ColetaDados::getRefinement(){
    return refinement;
}
void ColetaDados::setRefinement(int x){
    refinement=x;
}
void ColetaDados::setFirstLevel(){
    firstLevel++;
}
void ColetaDados::resetFirstLevel(){
    firstLevel=0;
}
int ColetaDados::getFirstLevel(){
    return firstLevel;
}
void ColetaDados::setRefinementLevel(){
    refinementLevel++;
}
int ColetaDados::getRefinementLevel(){
    return refinementLevel;
}
void ColetaDados::resetRefinementLevel(){
    refinementLevel=0;;
}
TComMv& ColetaDados::getMv(int x){
    switch(x){
        case 1:
        {
            return firstMv;
        }
        case 2:
        {   
            return rasterMv;
        }
        case 3:
        {
            return refinementMv;
        }
        default:
        {
            return predictorMv;
        }
    }
}
TComMv& ColetaDados::getPredMv(int x){
    switch(x){
        case 1:
        {
            return integerMv;
        }
        default:
        {
            return medianMv;
        }
    }
}
void ColetaDados::setTotalLevel(int x){
    totalLevel+=x;
}
void ColetaDados::resetTotalLevel(){
    totalLevel=0;
}
int ColetaDados::getTotalLevel(){
    return totalLevel;
}
void ColetaDados::setMaxLevel(int x){
    maxLevel=x;
}
int ColetaDados::getMaxLevel(){
    return maxLevel;
}
void ColetaDados::setIteration(){
    iteration++;
}
void ColetaDados::resetIteration(){
    iteration=0;
}
int ColetaDados::getIteration(){
    return iteration;
}

void ColetaDados::setTamWidth(int x){
    tamWidth=x;
}
int ColetaDados::getTamWidth(){
    return tamWidth;
}

void ColetaDados::setTamHeight(int x){
    tamHeight=x;
}
int ColetaDados::getTamHeight(){
    return tamHeight;
}

void ColetaDados::setQP(int x){
    QP=x;
}
int ColetaDados::getQP(){
    return QP;
}

void ColetaDados::incrementaNumPred (){
    numPred++;
}
int ColetaDados::getNumPred (){
    return numPred;
}
void ColetaDados::incrementaNumFirst (){
    numFirst++;
}
int ColetaDados::getNumFirst (){
    return numFirst;
}
void ColetaDados::incrementaNumRaster (){
    numRaster++;
}
int ColetaDados::getNumRaster (){
    return numRaster;
}
void ColetaDados::incrementaNumRefixFirst (){
    numRefixFirst++;
}
int ColetaDados::getNumRefixFirst (){
    return numRefixFirst;
}
void ColetaDados::incrementaNumRefixRaster (){
    numRefixRaster++;
}
int ColetaDados::getNumRefixRaster (){
    return numRefixRaster;
}

int ColetaDados::getNumTotal(){
    return (numPred+numFirst+numRaster+numRefixFirst+numRefixRaster);
}

void ColetaDados::setPredictorSAD(unsigned int x){
    predictorSAD = x;
}

unsigned int ColetaDados::getPredictorSAD(){
    return predictorSAD;
}

void ColetaDados::setFirstSAD(unsigned int x){
    firstSAD = x;
}

unsigned int ColetaDados::getFirstSAD(){
    return firstSAD;
}

void ColetaDados::setRasterSAD(unsigned int x){
    rasterSAD = x;
}

unsigned int ColetaDados::getRasterSAD(){
    return rasterSAD;
}

void ColetaDados::setBestDistance(int x){
    bestDistance = x;
}
int ColetaDados::getBestDistance(){
    return bestDistance;
}

void ColetaDados::setRdCostPred(unsigned int x){
    RdCostPred = x;
}

unsigned int ColetaDados::getRdCostPred(){
    return RdCostPred;
}

void ColetaDados::setRdCostFirst(unsigned int x){
    RdCostFirst = x;
}

unsigned int ColetaDados::getRdCostFirst(){
    return RdCostFirst;
}

void ColetaDados::setRdCostRaster(unsigned int x){
    RdCostRaster = x;
}

unsigned int ColetaDados::getRdCostRaster(){
    return RdCostRaster;
}