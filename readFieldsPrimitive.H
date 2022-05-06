    IOobject UHeader
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ
    );

    if (!UHeader.typeHeaderOk<volVectorField>(true))
    {
        Info<< "    No U field" << endl;
        continue;
    }

    volVectorField U
    (
        UHeader,
        mesh
    );
    
 
#include      "createPhi.H"
singlePhaseTransportModel laminarTransport(U, phi);

autoPtr<incompressible::turbulenceModel> turbulence
(
    incompressible::turbulenceModel::New(U, phi, laminarTransport)
);    
    
dimensionedScalar eps2("VSMALL", dimensionSet(0, 2, -3, 0, 0, 0, 0), VSMALL);
	
// ----------------------------------------------------------------------------
    
    
    IOobject UMeanHeader
    (
        "UMean",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ
    );

    if (!UMeanHeader.typeHeaderOk<volVectorField>(true))
    {
        Info<< "    No UMean field" << endl;
        continue;
    }

    volVectorField UMean
    (
        UMeanHeader,
        mesh
    );

// --------------------------------------------------------------------------
    volSymmTensorField UPrime2Mean
    (
        IOobject
        (
            "UPrime2Mean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );
	volScalarField UPrime2Meanxx(UPrime2Mean.component(symmTensor::XX));
    volScalarField UPrime2Meanyy(UPrime2Mean.component(symmTensor::YY));
    volScalarField UPrime2Meanzz(UPrime2Mean.component(symmTensor::ZZ));
    volScalarField UPrime2Meanxy(UPrime2Mean.component(symmTensor::XY));
// ----------------------------------------------------------------------------
      
    volScalarField pMean
    (
        IOobject
        (
            "pMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );

// ----------------------------------------------------------------------------

volScalarField kolmogorovLengthScale
(
      IOobject
      (
            "kolmogorovLengthScale",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
      ),
      mesh,
      dimensionedScalar("zero", dimensionSet(0, 1, 0, 0, 0, 0, 0), 0.0)
);          
    
volScalarField kolmogorovTimeScale
(
      IOobject
      (
            "kolmogorovTimeScale",
            runTime.timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::NO_WRITE
      ),
      mesh,
      dimensionedScalar("zero", dimensionSet(0, 0, 1, 0, 0, 0, 0), 0.0)
); 



/*
    IOobject vorticityMeanHeader
    (
        "vorticityMean",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ
    );

    if (!vorticityMeanHeader.typeHeaderOk<volVectorField>(true))
    {
        Info<< "    No vorticityMean field" << endl;
        continue;
    }

    volVectorField vorticityMean
    (
        vorticityMeanHeader,
        mesh
    );
    
        
    volSymmTensorField vorticity2PrimeMean
    (
        IOobject
        (
            "vorticity2PrimeMean",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ
        ),
        mesh
    );
    volScalarField vorticity2PrimeMeanxx(vorticity2PrimeMean.component(symmTensor::XX));
    volScalarField vorticity2PrimeMeanyy(vorticity2PrimeMean.component(symmTensor::YY));
    volScalarField vorticity2PrimeMeanzz(vorticity2PrimeMean.component(symmTensor::ZZ));
    volScalarField vorticity2PrimeMeanxy(vorticity2PrimeMean.component(symmTensor::XY));
*/    
