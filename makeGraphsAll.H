
const scalarField& y = channelIndexing.y();

makeGraph(y, UMeanXvalues, "Uf", path, gFormat);   
makeGraph(y, urmsValues, "urms", path, gFormat);
makeGraph(y, vrmsValues, "vrms", path, gFormat);
makeGraph(y, wrmsValues, "wrms", path, gFormat);
makeGraph(y, kValues, "k", path, gFormat);    
/*
makeGraph(y, vorticityMeanZvalues, "wz", path, gFormat);    
makeGraph(y, vorticityxrmsValues, "wxrms", path, gFormat);
makeGraph(y, vorticityyrmsValues, "wyrms", path, gFormat);
makeGraph(y, vorticityzrmsValues, "wzrms", path, gFormat);
*/
makeGraph(y, pMeanValues, "p", path, gFormat);

// ----------------------------------------------------------------------------
makeGraph(y, prodTKEMeanValues, "Pk", path, gFormat);
makeGraph(y, viscousDiffusionTKEMeanValues, "Dk", path, gFormat);
makeGraph(y, pressureDiffusionTKEMeanValues, "PIDk", path, gFormat);
makeGraph(y, turbulenceTransportTKEMeanValues, "Tk", path, gFormat);
makeGraph(y, convectionTKEMeanValues, "Ck", path, gFormat);
makeGraph(y, dissipationTKEMeanValues, "Ek", path, gFormat);
// ----------------------------------------------------------------------------
makeGraph(y, UPrime2MeanxxValues, "Rxx", path, gFormat);
makeGraph(y, UPrime2MeanxyValues, "Ryy", path, gFormat);
makeGraph(y, UPrime2MeanzzValues, "Rzz", path, gFormat);
makeGraph(y, UPrime2MeanxyValues, "Rxy", path, gFormat);
// ----------------------------------------------------------------------------
makeGraph(y, kolmogorovLengthScaleValues, "nuK", path, gFormat);
makeGraph(y, kolmogorovTimeScaleValues, "tauK", path, gFormat);



/*
makeGraph(y, epsilonValues, "epsilon", path, gFormat);
makeGraph(y, nuMeanValues, "nu", path, gFormat);
makeGraph(y, nuPrimeValues, "nuPrime", path, gFormat);
makeGraph(y, gammaDotMeanValues, "gammaDot", path, gFormat);
makeGraph(y, gammaDotPrimeValues, "gammaDotPrime", path, gFormat);
*/
