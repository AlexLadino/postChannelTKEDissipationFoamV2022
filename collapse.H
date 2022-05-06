fileName path(UMean.rootPath()/UMean.caseName()/"graphs"/UMean.instance());
mkDir(path);

scalarField UMeanXvalues
(
  channelIndexing.collapse(UMean.component(vector::X)())
);

scalarField UMeanYvalues
(
  channelIndexing.collapse(UMean.component(vector::Y)())
);

scalarField UMeanZvalues
(
  channelIndexing.collapse(UMean.component(vector::Z)())
);

scalarField pMeanValues(channelIndexing.collapse(pMean));
// ---------------------------------------------------------------------------
/*
scalarField vorticityMeanXvalues
(
  channelIndexing.collapse(vorticityMean.component(vector::X)())
);

scalarField vorticityMeanYvalues
(
  channelIndexing.collapse(vorticityMean.component(vector::Y)())
);

scalarField vorticityMeanZvalues
(
  channelIndexing.collapse(vorticityMean.component(vector::Z)())
);

scalarField vorticity2PrimeMeanxxValues(channelIndexing.collapse(vorticity2PrimeMeanxx));
scalarField vorticity2PrimeMeanyyValues(channelIndexing.collapse(vorticity2PrimeMeanyy));
scalarField vorticity2PrimeMeanzzValues(channelIndexing.collapse(vorticity2PrimeMeanzz));
scalarField vorticity2PrimeMeanxyValues(channelIndexing.collapse(vorticity2PrimeMeanxy, true));
*/
//  --------------------------------------------------------------------------
scalarField prodTKEMeanValues(channelIndexing.collapse(prodTKEMean));
scalarField viscousDiffusionTKEMeanValues(channelIndexing.collapse(viscousDiffusionTKEMean));
scalarField pressureDiffusionTKEMeanValues(channelIndexing.collapse(pressureDiffusionTKEMean));
scalarField turbulenceTransportTKEMeanValues(channelIndexing.collapse(turbulenceTransportTKEMean));
scalarField convectionTKEMeanValues(channelIndexing.collapse(convectionTKEMean));
scalarField dissipationTKEMeanValues(channelIndexing.collapse(dissipationTKEMean));
// ----------------------------------------------------------------------------
scalarField UPrime2MeanxxValues(channelIndexing.collapse(UPrime2Meanxx));
scalarField UPrime2MeanyyValues(channelIndexing.collapse(UPrime2Meanyy));
scalarField UPrime2MeanzzValues(channelIndexing.collapse(UPrime2Meanzz));
scalarField UPrime2MeanxyValues(channelIndexing.collapse(UPrime2Meanxy, true));
// ----------------------------------------------------------------------------
/*
scalarField DDtReynoldsStressMeanxxValues(channelIndexing.collapse(DDtReynoldsStressMeanxx));
scalarField DDtReynoldsStressMeanyyValues(channelIndexing.collapse(DDtReynoldsStressMeanyy));
scalarField DDtReynoldsStressMeanzzValues(channelIndexing.collapse(DDtReynoldsStressMeanzz));
scalarField DDtReynoldsStressMeanxyValues(channelIndexing.collapse(DDtReynoldsStressMeanxy, true));
*/
// ----------------------------------------------------------------------------
scalarField urmsValues(sqrt(mag(UPrime2MeanxxValues)));
scalarField vrmsValues(sqrt(mag(UPrime2MeanyyValues)));
scalarField wrmsValues(sqrt(mag(UPrime2MeanzzValues)));

scalarField kValues
(
      0.5*(sqr(urmsValues) + sqr(vrmsValues) + sqr(wrmsValues))
);

/*
scalarField vorticityxrmsValues(sqrt(mag(vorticity2PrimeMeanxxValues)));
scalarField vorticityyrmsValues(sqrt(mag(vorticity2PrimeMeanyyValues)));
scalarField vorticityzrmsValues(sqrt(mag(vorticity2PrimeMeanzzValues)));
*/

scalarField kolmogorovLengthScaleValues(channelIndexing.collapse(kolmogorovLengthScale));
scalarField kolmogorovTimeScaleValues(channelIndexing.collapse(kolmogorovTimeScale));

