const char * own_matrix_vector_mult = 
"__kernel void matrix_vector_mult(\n"
"          __global const float * A,\n"
"          __global const float * B, \n"
"          __global float * C,\n"
"          unsigned int wA, \n"
"          unsigned int hA, \n"
"          unsigned int blocks) \n"
"{ \n"
"  for( unsigned int tx = get_group_id(0); tx < blocks; tx += get_num_groups(0) ) \n"
"  {\n"
"      for(unsigned int j = get_local_id(0);j< hA;j+= get_local_size(0) ) \n"
"      {\n"
"          float value = 0.0; \n"
"          for( unsigned int k=0; k< wA; k++ )\n"
"              value += A[j * wA + k] * B[tx * wA +k];\n"
"          C[tx * hA + j] = value;\n"
"      }\n"
"  }\n"
"};\n";

const char * own_matrix_matrix_mult = 
"__kernel void matrix_matrix_mult(\n"
"          __global const float * A,\n"
"          __global const float * B, \n"
"          __global float * C,\n"
"          unsigned int wA, \n"
"          unsigned int hA, \n"
"          unsigned int wB, \n"
"          unsigned int blocks) \n"
"{ \n"
"  unsigned int n_elements_B = wB * wA; \n"
"  unsigned int n_elements_C = wB * hA; \n"
"  for( unsigned int tx = get_global_id(0); tx < blocks; tx += get_global_size(0) ) \n"
"  {\n"
"        for(unsigned int j=0;j< hA;j++) \n"
"        { \n"
"            for( int k = 0; k < wB; k++ ) \n"
"            { \n"
"                unsigned int elemC = tx * n_elements_C + j*wB + k; \n"
"                C[elemC] = 0.0; \n"
"                for(unsigned int l=0;l< wA;l++) \n"
"                { \n"
"                    unsigned int elemA = j * wA + l; \n"
"                    unsigned int elemB = tx * ( wA*wB ) + l*wB + k; \n"
"                    C[elemC] += A[elemA] * B[elemB]; \n"
"                } \n"
"            }     \n"
"        } \n"
"  }\n"
"};\n";

const char * own_matrix_vector_global = 
"__kernel void matrix_vector_global(\n"
"          __global const float * A,\n"
"          __global const float * B, \n"
"          __global float * C,\n"
"          unsigned int wA, \n"
"          unsigned int hA, \n"
"          unsigned int blocks, \n"
"          unsigned int nVariables) \n"
"{ \n"
"  for( unsigned int tx = get_global_id(0); tx < blocks; tx += get_global_size(0) ) \n"
"  {\n"
"      for(unsigned int j=0;j< hA;j++)\n"
"      {\n"
"            for( unsigned int k = 0; k < nVariables; k++ )\n"
"            {\n"
"                unsigned int elemC = tx * ( nVariables * hA ) + j * nVariables + k;\n"
"                \n"
"               float value = 0;\n"
"               \n"
"               for( unsigned int l = 0; l < wA; l++ )\n"
"               {\n"
"                    unsigned int elemA = j * wA + l;\n"
"                    unsigned int elemB = tx * ( nVariables * wA ) + l * nVariables + k;\n"
"                    \n"
"                    value += A[elemA] * B[elemB];\n"
"                }\n"
"                C[elemC] = value;\n"
"            }\n"
"      }\n"
"  }\n"
"};\n";


