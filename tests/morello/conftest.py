import os
import pytest
import stat
import subprocess
from pathlib import Path

def abspath(x):
    return Path(x).absolute()

def pytest_addoption(parser):
    morello_root_dir = os.getenv("MORELLO_ROOT", str(Path.home() / "cheri"))
    parser.addoption("--qemu", type=abspath, help="Path to qemu-system-morello",
                     default=str(Path(morello_root_dir, "output/morello-sdk/bin/qemu-system-morello")))
    parser.addoption("--morello-tests-dir", type=abspath, help="Path to the morello tests", required=True)


def decompress_all_elf_files(tests_dir: Path):
    for root, _, files in os.walk(str(tests_dir)):
        for file in files:
            if file.endswith('.elf.gz'):
                compressed_file = Path(root, file)
                elf_file = Path(root, file[:-3])
                if not elf_file.exists() or elf_file.stat()[stat.ST_MTIME] < compressed_file.stat()[stat.ST_MTIME]:
                    subprocess.check_call(["gunzip", "-kf", str(compressed_file)], stdin=subprocess.DEVNULL)


# noinspection PyUnresolvedReferences
def pytest_configure(config):
    pytest.morello_tests_dir = config.getoption("--morello-tests-dir")
    print("Morello tests dir is", pytest.morello_tests_dir)
    pytest.morello_qemu = config.getoption("--qemu")
    print("Morello QEMU is", pytest.morello_qemu)

    # In xdist, only the controller process should decompress test files before workers start
    if not hasattr(config, "workerinput") and not hasattr(config, "slaveinput"):
        print("Decompressing test ELF files before test execution...")
        decompress_all_elf_files(pytest.morello_tests_dir)
