from distutils.core import setup, Extension


def main():
    setup(
        name="euler",
        version="1.0.0",
        description="Python interface for the Euler integrator method library",
        author="Juan Vanegas",
        author_email="juan@vanegas.com",
        ext_modules=[
            Extension("euler", ["integrator/eulermodule.c", "integrator/integrator.c"])
        ],
    )


if __name__ == "__main__":
    main()
