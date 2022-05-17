search_dir_east =`ls /home/sigmind/Videos/sample_videos/*.h264`
search_dir_west =`ls /home/sigmind/Videos/sample_videos/*.h264`
search_dir_noth =`ls /home/sigmind/Videos/sample_videos/*.h264`
search_dir_south =`ls /home/sigmind/Videos/sample_videos/*.h264`

len_east=${#search_dir_east[@]}
len_west=${#search_dir_west[@]}
len_north=${#search_dir_noth[@]}
len_south=${#search_dir_south[@]}

no_video = $false

while [ !$no_video ]
do

  uri_arg_string = ""


  if [ len_east > 0 ]
    uri_arg_string = '$uri_arg_string file://$search_dir_east[len_east-1]'
    len_east = len_east-1
    east_has_video = $true
  then
    $east_has_video = $false
  fi


  if [ len_west > 0 ]
    uri_arg_string = '$uri_arg_string file://$search_dir_west[len_west-1]'
    len_west = len_west-1
    west_has_video = $true
  then
    $west_has_video = $false
  fi


  if [ len_north > 0 ]
    uri_arg_string = '$uri_arg_string file://$search_dir_north[len_north-1]'
    len_north = len_north-1
    north_has_video = $true
  then
    $north_has_video = $false
  fi
  

  if [ len_south > 0 ]
    uri_arg_string = '$uri_arg_string file://$search_dir_south[len_south-1]'
    len_south = len_south-1
    south_has_video = $true
  then
    $south_has_video = $false
  fi


  if [$east_has_video] || [$west_has_video] || [$north_has_video] || [$south_has_video] 
    python3 deepstream_imagedata-multistream.py $uri_arg_string frames
  then
    $no_video = $true
  fi
done




