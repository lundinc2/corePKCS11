# corePKCS11 Library 

This repository contains a software based implementation of the PKCS #11 interface (API)  to enable rapid development and flexibility when developing  applications that rely on cryptographic operations.

Only a subset of the PKCS #11 standard is implemented, with a focus on operations involving asymmetric keys, random number generation, and hashing. 

The targeted use cases include certificate and key management for TLS authentication and code-sign signature verification, on small embedded devices.

corePKCS11 is implemented on PKCS #11 v2.4.0, the full PKCS #11 standard can be found on the [oasis website](http://docs.oasis-open.org/pkcs11/pkcs11-base/v2.40/os/pkcs11-base-v2.40-os.html).

This library has gone through code quality checks including verification that no function has a [GNU Complexity](https://www.gnu.org/software/complexity/manual/complexity.html) score over 8, and checks against deviations from mandatory rules in the [MISRA coding standard](https://www.misra.org.uk/MISRAHome/MISRAC2012/tabid/196/Default.aspx).  Deviations from the MISRA C:2012 guidelines are documented under [MISRA Deviations](MISRA.md). This library has also undergone both static code analysis from [Coverity static analysis](https://scan.coverity.com/) and validation of memory safety and proof of functional correctness through the [CBMC automated reasoning tool](https://www.cprover.org/cbmc/).

See memory requirements for the latest release [here](https://docs.aws.amazon.com/embedded-csdk/202103.00/lib-ref/libraries/standard/corePKCS11/docs/doxygen/output/html/pkcs11_design.html#pkcs11_memory_requirements).

**corePKCS11 v3.0.0 [source code](https://github.com/FreeRTOS/corePKCS11/tree/v3.0.0/source) is part of the [FreeRTOS 202012.00 LTS](https://github.com/FreeRTOS/FreeRTOS-LTS/tree/202012.00-LTS) release.**

# Purpose

The purpose of this library is to provide a PKCS #11 implementation that allows for rapid prototyping and developing. Once a secure cryptoprocessor is selected, this library must be replaced with a PKCS #11 implementation that abstracts
said cryptoprocessor.

Since the PKCS #11 interface is defined as part of the PKCS #11 [specification](https://docs.oasis-open.org/pkcs11/pkcs11-base/v2.40/os/pkcs11-base-v2.40-os.html) replacing this library with another implementation 
should require little porting effort, as the interface will not change. The system tests distributed in this repository can be leveraged to verify the behavior of a different implementation is similar to corePKCS11.

Generally vendors for secure cryptoprocessors such as TPM, HSM, Secure Element, or any other type of secure hardware enclave, distribute a PKCS #11 implementation with the hardware. 
The recommendation is to use a secure cryptoprocessor, and replace corePKCS11 with an implementation compatible with said cryptoprocessor.

## Building Unit Tests.

### PKCS Config File

The PKCS #11 library exposes build configuration macros that are required for building the library.
A list of all the configurations and their default values are defined in the doxygen documentation for this library.

### Platform Prerequisites

- For building the library, **CMake 3.13.0 or later** and a **C90 compiler**.
- For running unit tests, Ruby 2.0.0 or later is additionally required for the CMock test framework (that we use).
- For running the coverage target, gcov is additionally required.

### Steps to build **Library** and **Unit Tests**

### Checkout CMock Submodule
By default, the submodules in this repository are configured with `update=none` in [.gitmodules](.gitmodules) to avoid increasing clone time and disk space usage of other repositories (like [amazon-freertos](https://github.com/aws/amazon-freertos) that submodule this repository.

To build unit tests, the submodule dependency of CMock is required. Use the following command to clone the submodule:
```
git submodule update --checkout --init --recursive test/unit-test/CMock
```

1. Go to the root directory of this repository. (Make sure that the **CMock** submodule is cloned as described [above](#checkout-cmock-submodule))

1. Run *cmake* while inside build directory: `cmake -S ../test/unit-test -B build`

1. Run this command to build the library and unit tests: `make -C build all`

1. The built library will be present in `build/lib` folder, and generated test executables will be present in `build/bin/tests` folder.

1. Run `ctest` to execute all tests and view the test run summary.

## Reference examples

The FreeRTOS-Labs repository contains demos using the PKCS #11 library [here](https://github.com/FreeRTOS/FreeRTOS-Labs/tree/master/FreeRTOS-Plus/Demo/FreeRTOS_Plus_PKCS11_Windows_Simulator/examples) using FreeRTOS on the Windows simulator platform. These can be used as reference examples for the library API.

## Generating documentation

The Doxygen references were created using Doxygen version 1.8.20. To generate the
Doxygen pages, please run the following command from the root of this repository:

```shell
doxygen docs/doxygen/config.doxyfile
```

## Security

See [CONTRIBUTING](CONTRIBUTING.md#security-issue-notifications) for more information.

## License

This library is licensed under the MIT-0 License. See the LICENSE file.

