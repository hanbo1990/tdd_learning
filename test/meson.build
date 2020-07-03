# gtest_proj = subproject('gtest')


tests_src = files(
  'GMockTest.cpp',
  'test_checkoutExample.cpp',
  )

tests_src += src_files

gtestexe = executable(
  'gtest-all',
  tests_src,
  include_directories : test_dirs,
  dependencies : [
    dependency('gtest', main: false, method: 'pkg-config'),
    dependency('gmock', method: 'pkg-config'),
    dependency('gtest_main', method: 'pkg-config'),
    deps
  ],
  cpp_args : ['--coverage', '-DUNIT_TEST' ],
  link_args : ['-lgcov', '--coverage' ],
)

# you can use ninja test in the build foler to run the testing
test('gtest tests', gtestexe)
