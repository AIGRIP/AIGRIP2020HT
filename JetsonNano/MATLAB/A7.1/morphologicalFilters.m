function[segmentationMask] = morphologicalFilters(colourSegmentationMask, centerOfObjectX, centerOfObjectY)


%Fill up the hole in the binary image.
maskFill =imfill(colourSegmentationMask,'holes');

stats = regionprops(maskFill,'Area','Centroid','PixelIdxList');

area = [stats.Area]';

[numRegions,~] = size(area);

centroid = reshape([stats.Centroid],[2,numRegions])';

centroid = centroid .* (area > 250);
centroid(centroid == 0) = NaN;

distances = sqrt(sum(bsxfun(@minus, centroid, [centerOfObjectX,centerOfObjectY]).^2,2));

[~, index] = min(distances);

centroid(index,:)

segmentationMask = zeros(size(colourSegmentationMask),'logical');

segmentationMask = PixelIdxList


end