    Info<< nl << "Reading transportProperties" << endl;

    IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );

    Info<< "Reading kinematic viscosity nuVisc\n" << endl;

    scalarField nuVisc
    (
        transportProperties.lookup("nuVisc")
    );
