// MemoryMappedFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

boost::filesystem::path path_src{ "D:/Harbor_8192x4096_30fps_8bit_420_erp.yuv" };
boost::filesystem::path path_dest{ "E:/Harbor_8192x4096_30fps_8bit_420_erp.yuv" };

int main()
{

    boost::iostreams::mapped_file_source mmap_src{ path_src };
    boost::iostreams::mapped_file_params params;
    params.path = path_dest.string();
    params.flags = boost::iostreams::mapped_file::mapmode::readwrite;
    params.new_file_size = mmap_src.size();
    boost::iostreams::mapped_file_sink mmap_dest{ params };
    std::copy(mmap_src.begin(), mmap_src.end(), mmap_dest.begin());

    return 0;
}

